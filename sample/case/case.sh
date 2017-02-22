case $rental in
	("bus") case yolo in
			("bonjour") echo hello ;; 
			("hello") echo bonjour ;;
		esac
		case yala in
			("bonjour") echo hello ;;
			("hello") echo yolo ;;
		esac ;; 
	("van") echo "For $rental rental is Rs.10 per k/m.";;
	("jeep") echo "For $rental rental is Rs.5 per k/m.";;
esac
