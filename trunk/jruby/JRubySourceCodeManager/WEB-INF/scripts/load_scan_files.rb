##
## 11/10/2006
##

include_class 'org.spirit.bean.impl.BotListSystemWebFile'

class LoadScanFiles
  
  def initialize(log, context)
    @load_file = "WEB-INF/scripts/pydb/scan_files.db"
    @context = context
    @log = log

  end

  def readFile()
    @log.info @load_file

    # Get the context DAO bean (see the spring config file)
    daoFileBean = @context.getBean("postWebFileDaoBean")

    File.open(@load_file, "r") do |curfile|
      curfile.each_line { |line| 
        # space tokenize the line
        data = line.split
        
        if data[0]
          file = BotListSystemWebFile.new
          file.filename = data[0]
          file.fsize = data[1].to_i;
          file.fmtime = data[2].to_i;
          file.fext = data[3]
          file.projectname = data[4];
          daoFileBean.createWebFile(file)
        end
      }
    end
  end    
  
  #
  # Entry Point, invoked from java client
  def initializeApplication
    @log.info "** INFO ** ReinitApplication"
    readFile()    
  end

end

LoadScanFiles::new($log, $context)
