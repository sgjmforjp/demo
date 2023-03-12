FROM centos:latest

ENV TZ Asia/Shanghai

RUN set -xe \
    && cat /etc/redhat-release \
    && cd /etc/yum.repos.d \
    && sed -i 's/mirrorlist/#mirrorlist/g' /etc/yum.repos.d/CentOS-* \
    && sed -i 's|#baseurl=http://mirror.centos.org|baseurl=http://vault.centos.org|g' /etc/yum.repos.d/CentOS-* \
    && yum -y update \
    && yum -y upgrade \
    && yum -y groupinstall 'Development Tools' \
    && yum -y install procps-ng curl file git wget \
    && yum -y install openssh openssh-server openssh-clients \
    && mkdir -p /var/run/sshd \
    && rm -rf /run/nologin \
    && ssh-keygen -q -t rsa -b 2048 -f /etc/ssh/ssh_host_rsa_key -N '' \
    && ssh-keygen -q -t ecdsa -f /etc/ssh/ssh_host_ecdsa_key -N '' \
    && ssh-keygen -t dsa -f /etc/ssh/ssh_host_ed25519_key  -N '' \
    && /bin/echo 'root:1234' |chpasswd \
    && /bin/echo -e "LANG=\"en_US.UTF-8\"" > /etc/default/local \
    && /bin/sed -i 's/.*session.*required.*pam_loginuid.so.*/session optional pam_loginuid.so/g' /etc/pam.d/sshd \
    && /bin/echo -e "LANG=\"en_US.UTF-8\"" > /etc/default/local \
    && /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" \
    && (echo; echo 'eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"') >> /root/.bash_profile \
    && eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)" \
    && source /root/.bash_profile \
    && /usr/sbin/sshd

ENTRYPOINT ["/usr/sbin/init"]
CMD ["systemctl"]
