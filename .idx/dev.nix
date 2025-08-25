{ pkgs, ... }: {
  channel = "stable-24.05"; # or "unstable"

  packages = [
    # pkgs.temurin-bin-17 # JAVA/JSP 실습때만 사용
    pkgs.gcc
    pkgs.rsync  # 파일 복붙 라이브러리
    # pkgs.adoptopenjdk-bin
    # pkgs.go
    pkgs.python311
    # pkgs.python311Packages.pip
    # pkgs.nodejs_20
    # pkgs.nodePackages.nodemon
	# 설치 가능:  https://search.nixos.org/packages
  ];

  env = {
    SOME_ENV_VAR = "환경변수 예시";
  };

  idx.extensions = [
    # "angular.ng-template"
	# 설치 가능:  https://open-vsx.org/ and use "publisher.id"
  ];

  idx.previews = {
    enable = false;
    previews = {
      web = {
        command = [
          "npm"
          "run"
          "start"
          "--"
          "--port"
          "$PORT"
          "--host"
          "0.0.0.0"
          "--disable-host-check"
        ];
        manager = "web";
        # Optionally, specify a directory that contains your web app
        # cwd = "app/client";
      };
    };
  };
}