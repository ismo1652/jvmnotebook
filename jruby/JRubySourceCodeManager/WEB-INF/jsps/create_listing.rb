##
## Berlin Brown
## 11/4/2006
##
## create_listing.rb
##

include_class 'org.spirit.form.BotListPostListingForm'
include_class 'org.spirit.bean.impl.BotListPostListing'

class CreateListingController
		
  def initialize(daohelper)
    @daohelper = daohelper
  end    
  
  def getModel(request)
    postListing = BotListPostListingForm.new()
    postListing.viewName = nil
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
    @daohelper.createPostListing(listing)
  end
  
  def onSubmit(request, response, form, errors)
    transformFormData(form)
    form.viewName = "calculator_results"
    return form
  end
end

CreateListingController.new($daohelperlisting)

## End of Script ##

