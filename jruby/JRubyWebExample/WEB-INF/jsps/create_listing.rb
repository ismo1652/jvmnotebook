##
## Berlin Brown
## 11/4/2006
##
## create_listing.rb
##

include_class 'org.spirit.form.BotListPostListingForm'
include_class 'org.spirit.bean.impl.BotListPostListing'
include_class 'org.spirit.bean.impl.BotListCityListing'
include_class 'org.spirit.bean.impl.BotListCalculatorVerification'
include_class 'org.spirit.util.BotListSessionManager'

include_class 'org.spirit.spring.validate.BotListPostListingValidator'

include_class 'org.apache.commons.logging.Log'
include_class 'org.apache.commons.logging.LogFactory'

class CreateListingController
		
  def initialize(controller)
    @controller = controller
    @daohelpercity = controller.cityListingDao
    @daohelperpost = controller.postListingDao
    @log = LogFactory::getLog("org.jruby")
  end    
  
  
  #
  # Generate the view
  def getModel(request)
    postListing = BotListPostListingForm.new()
    postListing.viewName = nil

    calc = generateCalcVerification()
    calc.solution = calc.firstInput + calc.secondInput
    postListing.firstInput = calc.firstInput
    postListing.secondInput = calc.secondInput
    postListing.solution = calc.solution

    cur_session = request.getSession(false)
    # Check the previous session object for the previous value
    # used in conjunction with onSubmit()
    prev_calc = cur_session.getAttribute(BotListSessionManager::CALC_VERIFY_OBJECT)
    if prev_calc != nil
      postListing.prevSolution = prev_calc.solution
    end
    
    cur_session.setAttribute(BotListSessionManager::CALC_VERIFY_OBJECT, calc)
    
    # Also set the validator
    @controller.setValidator(BotListPostListingValidator.new())   
    return postListing
  end
  
  
  #
  # Transform the form data to the
  # data object.
  def transformFormData(form)
    listing = BotListPostListing.new
    listing.email = form.email
    listing.message = form.message
    listing.title = form.title
    listing.age = form.age
    listing.category = 'general'
    if form.mainUrl
      listing.mainUrl = form.mainUrl
    end
    if form.keywords
      listing.keywords = form.keywords
    end
    return listing
  end
  
  #
  # Generate the calculator verification, input and solution
  def generateCalcVerification()
    calc = BotListCalculatorVerification.new
    calc.firstInput = rand 30
    calc.secondInput = rand 10
    calc.solution = calc.firstInput + calc.secondInput
    return calc
  end
    
  #
  # Processed when the form is submitted, 
  # see the controller 'processFormSubmission()' method
  def onSubmit(request, response, form, errors)   
    
    #
    # Check the errors first.
    if errors.getErrorCount() > 0
      # Revert back to the entry screen
      form.viewName = "create_listing"
      return form
    end
    
    # Get the city object from the session
    cur_session = request.getSession(false)
    citybean = cur_session.getAttribute(BotListSessionManager::CURRENT_CITY_SETTING)
    cityId = citybean.id

    listing = transformFormData(form)

    # Get the bean from the DB as opposed to off the session table
    sessionFactory = @daohelpercity.getSessionFactory()
    hbm_session = sessionFactory.openSession()
    tx = hbm_session.beginTransaction()
    city = hbm_session.load("org.spirit.bean.impl.BotListCityListing", cityId, nil)

    listing.cityId = cityId
    city.listings.add(listing)
    tx.commit()
    hbm_session.close()

    # Navigate to the confirmation page
    form.viewName = "createconfirm"
    return form

  end
end

CreateListingController.new($controller)

## End of Script ##

