##
## Berlin Brown
## 11/4/2006
##
## create_listing.rb
##

include_class 'org.spirit.form.BotListPostListingForm'
include_class 'org.spirit.bean.impl.BotListPostListing'
include_class 'org.spirit.bean.impl.BotListCityListing'
include_class 'org.spirit.util.BotListSessionManager'


include_class 'org.apache.commons.logging.Log'
include_class 'org.apache.commons.logging.LogFactory'

class ViewListingController
		
  def initialize(controller)
    @controller = controller
    @daohelper = @controller.userVisitLogDao
  end    
  
  #
  # Generate the view
  def getModel(request)
    
    # Audit the request
    @controller.auditLogPage(request, "stats.html")    
    totalvisits = @daohelper.getVisitAuditCount()
    uniquevisits = @daohelper.getUniqueVisitAuditCount()
    return {
      'totalvisits' => totalvisits,
      'uniquevisits' => uniquevisits
    }

    return postbean
  end
  
  #
  # Processed when the form is submitted, 
  # see the controller 'processFormSubmission()' method
  def onSubmit(request, response, form, errors)      
    return form
  end
end

ViewListingController.new($controller)

## End of Script ##

