
class CLStatus {
public:
    CLStatus(long lReturnCode, long lErrorCode);
    virtual ~CLStatus();

public:
    bool IsSuccess();
    long GetErrorCode();

private:
    long m_lReturnCode;
    long m_lErrorCode;
};