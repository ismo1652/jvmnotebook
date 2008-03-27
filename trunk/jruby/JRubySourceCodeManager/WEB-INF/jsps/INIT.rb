class RadApp

	@@daoNames = []

	def initializeApplication
		reinitApplication
	end

	def reinitApplication
		# This method is automatically run when the RAD controller is first initialized.
		# It's useful for setting up global variables and other global context.
		print "INFO: ReinitApplication"
	end

	def getModel(request)
		print "INFO: GetModel()"
		reinitApplication				
	end
end

RadApp::new
