#
# Berlin Brown
require 'java'
include_class 'java.net.HttpURLConnection' unless defined? HttpURLConnection
include_class 'org.spirit.loadtest.LoadTestManager' unless defined? LoadTestManager

class RemoteSync
	attr_accessor :key_request_url
    def initialize()		
		@key_request_url = nil
		@remote_send_url = nil
		@send_data = nil		
    end        
    def getItemData()
		begin
			connect_res = LoadTestManager.connectURL(@key_request_url, false)
			requestKey = connect_res[1]	
			puts requestKey
		rescue Exception => e
			puts e
		end
		# End of method
    end    
end

def connect(key_url)
	puts "INFO: keyurl=#{key_url}"	
	remoteSync = RemoteSync.new	
	remoteSync.key_request_url = key_url
	remoteSync.getItemData
end

def main()		
	puts "running"
	start_time = Time.now
		
	key_url = ARGV[0]		
	connect(key_url)	
	end_time = Time.now
	diff_time = end_time - start_time
	printf "processing sync in %.5f s\n", diff_time
	puts "done"	
end

main()

# End of script