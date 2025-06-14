clean:
	find . -type f -name "*.bin" -delete
	find . -type f -name "*.in" -delete
	find . -type f -name "*.out" -delete
	find . -type d -name ".cph" -exec rm -rf {} +
	find . -type d -name ".vscode" -exec rm -rf {} +