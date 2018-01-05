package xyz.vimtool.Socket;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

/**
 * socket长连接client
 *
 * @author zhangzheng
 * @version 1.0
 * @since 2018-1-5
 */
public class LongConnectClient {

    private static final String HOST = "127.0.0.1";

    private static final int PORT = 5987;

    private static class Connect extends Thread {

        private Socket socket;

        private Thread tReceive;

        private Thread tKeep;

        private OutputStream outStr = null;

        private InputStream inStr = null;

        Connect(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            tReceive = new Thread(new LongConnectClient.Connect.ReceiveThread());
            tKeep = new Thread(new LongConnectClient.Connect.KeepThread());
            try {
                outStr = socket.getOutputStream();
                inStr = socket.getInputStream();
            } catch (Exception e) {
                e.printStackTrace();
            }
            tKeep.start();
            tReceive.start();
        }

        private class KeepThread implements Runnable {
            @Override
            public void run() {
                try {
                    System.out.println("=====================开始发送心跳包==============");
                    while (true) {
                        try {
                            Thread.sleep(1000);
                        } catch (InterruptedException e) {
                            // TODO Auto-generated catch block
                            e.printStackTrace();
                        }
                        System.out.println("发送心跳数据包");
                        outStr.write("heart jjj beat".getBytes());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }

        private class ReceiveThread implements Runnable {
            @Override
            public void run() {
                try {
                    System.out.println("==============开始接收数据===============");
                    while (true) {
                        byte[] b = new byte[1024];
                        int r = inStr.read(b);
                        if(r > -1){
                            String str = new String(b);
                            System.out.println(str + "[" + Thread.currentThread().getName() + "]");
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }
    }



    public static void main(String[] args) throws Exception {
        for (int i = 0; i < 10; i++) {
            Connect connect = new Connect(new Socket(HOST, PORT));
            connect.start();
        }
    }
}
