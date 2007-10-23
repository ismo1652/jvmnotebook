##
## Berlin Brown
## 11/4/2006
##
## create_listing.rb
##

include_class 'org.spirit.util.BotListSessionManager'

class SectionController
		
  def initialize(controller)
    @controller = controller
    @daohelper = @controller.cityListingDao
  end    
  
  def getModel(request)

    city = request.getParameter("city")    
    if city != nil
      
      city.strip!
      # Quick sql injection protection
      invalid_sql = false
      if city.include? "'" or
          city.include? "\"" or
          city.include? "=" or
          city.include? ";" or
          city.include? "%22"
        invalid_sql = true
      end
      
      # Audit the request
      @controller.auditLogPage(request, "sections.html")

      citybean = @daohelper.readCityListing(city.to_i())
    end

    # 
    # Save the session parameter
    cur_session = request.getSession(false)
    if (cur_session == nil)
      cur_session = cur_session.getSession()
    end

    cur_session.setAttribute(BotListSessionManager::CURRENT_CITY_SETTING, citybean)

    return {
      'city' => citybean
    }
  end
 
  
  def onSubmit(request, response, form, errors)
    return form
  end
end

SectionController.new($controller)

## End of Script ##

