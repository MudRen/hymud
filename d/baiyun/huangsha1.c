 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "�̺���ɳ");
        set("long", @LONG 
������ȥ��������ӣ���ϼѤ�ã����������֮�䣬������Ҳ����ǧ��Ƭ��ʵ�
���ˡ�һֻ��Ÿ��������𣬳����˺�������������ǵ��ഺһ�㣬һȥ���ٻ�ͷ��
�����ǽ�ӲӵĻ�ɳ���������ϵ���ͯ���Ž�Ѿ�������Ų�֪����ͯҥ�����ĸ���
���ź������������
LONG 
           ); 
        set("exits",  
           ([  
       "south" : __DIR__"baiyunentrance",
       "north" : __DIR__"baiyundu",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/fishboy" : 2,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1530); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}    
