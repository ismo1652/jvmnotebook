##
## Berlin Brown
## 11/4/2006
##
## create_listing.rb
##

#include_class 'org.spirit.bean.impl.BotListPostListing'

class SystemFileController
		
  def initialize(daohelper)
    @daohelper = daohelper
  end    
  
  def getModel(request)
    project = request.getParameter("project")    
    if project != nil
      
      project.strip!
      # Quick sql injection protection
      invalid_sql = false
      if project.include? "'" or
          project.include? "\"" or
          project.include? "=" or
          project.include? ";" or
          project.include? "%22"
        invalid_sql = true
      end
      
      filename = project.split(".")[0]
      if !invalid_sql
        # Extract only the
        query = "from org.spirit.bean.impl.BotListSystemWebFile file where (projectname = '#{filename}') order by file.filename"
        @daohelper.findFileQuery = query
      else
        # Use the default
        @daohelper.findFileQuery = nil
      end
    else
      # Use the default
      @daohelper.findFileQuery = nil
    end

    files = @daohelper.findWebFiles()
    return { 
      'files' => files 
    }
  end
 
  
  def onSubmit(request, response, form, errors)
    return form
  end
end

SystemFileController.new($daohelperfile)

## End of Script ##

