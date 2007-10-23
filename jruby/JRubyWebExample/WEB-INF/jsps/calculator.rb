##
## Berlin Brown
## 11/4/2006
## calculator.rb
##

include_class 'org.spirit.bean.impl.BotListUserVisitAudit'

class CalculatorController
	
	def initialize(daohelper)
          @daohelper = daohelper
	end
	
	def getModel(request)
          print "\n\n\n*** getModel() Calculator Controller\n"
          
          totalvisits = @daohelper.getVisitAuditCount()
          return {
            'x' => 10, 
            'y' => 20,
            'totalvisits' => totalvisits
          }
	end

	def onSubmit(request, response, form, errors)
          print "\n\n\n*** onSubmit() Calculator Controller\n"
          
          party_poll_form = form['poll']
          party_poll = ""
          if party_poll_form == 'DEM'
            party_poll = 'DEM'
          else
            party_poll = 'REP'
          end
          
          # Keep an audit of visited users
          audit = BotListUserVisitAudit.new
    	  audit.remoteHost = request.getRemoteAddr()
          audit.party_poll = party_poll
          @daohelper.createVisitAudit(audit)
          
          form['total'] = form['x'].to_i + form['y'].to_i
          form['subtract'] = form['x'].to_i - form['y'].to_i
          form['multiply'] = form['x'].to_i * form['y'].to_i
          form['average'] = (form['x'].to_i + form['y'].to_i) / 2.0
          form['viewName'] = 'calculator_results'
          
          # Print the total visits
          totalvisits = @daohelper.getVisitAuditCount()
          dems = @daohelper.getVisitDemCount()
          reps = @daohelper.getVisitRepCount()

          form['totalvisits'] = totalvisits
          form['dems'] = dems
          form['reps'] = reps
          
          return form
	end
end

CalculatorController.new($daohelperaudit)

## End of Script ##

