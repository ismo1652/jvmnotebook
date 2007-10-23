##
## Berlin Brown
## 11/4/2006
##

include_class 'org.spirit.util.BotListSessionManager'

class ListingsController
		
  def initialize(controller)
    @controller = controller
    @daohelper = @controller.postListingDao
  end    
  
  def getModel(request)
    
    #
    # Get the session object
    cur_session = request.getSession(false)
    citybean = cur_session.getAttribute(BotListSessionManager::CURRENT_CITY_SETTING)    
    cityId = citybean.id
    query = "from org.spirit.bean.impl.BotListPostListing as posts where posts.cityId = '#{cityId}' order by posts.createdOn desc"
    postListings = @daohelper.listPostListings(query)
    
    # Audit the request
    @controller.auditLogPage(request, "listings.html")

    return {
      'listings' => postListings,
      'city' => citybean
    }
  end
 
  
  def onSubmit(request, response, form, errors)
    return form
  end
end

ListingsController.new($controller)

## End of Script ##

