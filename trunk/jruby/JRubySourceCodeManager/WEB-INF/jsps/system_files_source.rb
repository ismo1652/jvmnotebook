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

    fsrc = request.getParameter("src")    
    if fsrc != nil
      
      fsrc.strip!
      # Quick sql injection protection
      invalid_sql = false
      if fsrc.include? "'" or
          fsrc.include? "\"" or
          fsrc.include? "=" or
          fsrc.include? ";" or
          fsrc.include? "%22"
        invalid_sql = true
      end
      
      if !invalid_sql
        # Extract only the
        query = "from org.spirit.bean.impl.BotListSystemWebFile file where (file.fext = '#{fsrc}') order by file.filename"
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
      'viewName' => 'system_files',
      'files' => files
    }
  end
 
  
  def onSubmit(request, response, form, errors)
    return form
  end
end

SystemFileController.new($daohelperfile)

## End of Script ##

