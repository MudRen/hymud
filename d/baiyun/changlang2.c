 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "��");
        set("long", @LONG 
����¥�������ڣ�˭Ҳ�޷��������֮�о�Ȼ�����һ����ֱ���ĳ���������
�Ե��Ų���ĳ����ƣ������䲻��������Ҳ�ɱ��·���ƺ���������ɽ������Ȼ��Ѩ
������ɣ��˹����䴦������խ����ʱȴ��Ȼ������ֻ�����н��ͣ����г�������ˮ
֮��������������ö��������������ǰ���ƺ���Щ��ƹ����������
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"changlang",
       "south" : __DIR__"changlang3",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/jianchi" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2022); 
        set("coor/z",20); 
        setup(); 
        

        replace_program(ROOM); 
}       
