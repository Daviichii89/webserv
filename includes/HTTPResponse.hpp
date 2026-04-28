#ifndef HTTPRESPONSE_HPP
# define HTTPRESPONSE_HPP

# include <string>
# include <map>

class HTTPResponse
{
public:
	HTTPResponse();
	HTTPResponse(int statusCode);
	~HTTPResponse();
	HTTPResponse(const HTTPResponse& other);
	HTTPResponse& operator=(const HTTPResponse& other);

	// Setters
	void	setStatusCode(int code);
	void	setHeader(const std::string& name, const std::string& value);
	void	setBody(const std::string& body);

	// Getters
	int					getStatusCode() const;
	const std::string&	getBody() const;

	// Serialization
	std::string	serialize() const;

	// Factory methods
	static HTTPResponse	buildErrorResponse(int code);
	static HTTPResponse	buildErrorResponse(int code, const std::string& customBody);
	static HTTPResponse	buildRedirectResponse(int code, const std::string& location);

private:
	int									_statusCode;
	std::string							_statusMessage;
	std::map<std::string, std::string>	_headers;
	std::string							_body;

	void	_setDateHeader();
	void	_setServerHeader();

	static std::string	_generateErrorPage(int code, const std::string& message);
};

#endif
