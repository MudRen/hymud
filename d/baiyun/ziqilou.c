 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "��������¥");
        set("long", @LONG 
�˼��ǰ��Ƴ��д������¥�һ����ľ��̵Ļ������������ȣ������ü�����
���¡�¥�ڵ�����������ڻԻͣ�����������ˣ��޲�������䣬Զ��ǧ������Ͻ�
�Ǵ��Ҳ������ˡ���¥�ڰ���������챦����������Ĺ�����ȸ���������Ŀ��
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"skystreet",
       "up" : __DIR__"ziqilou2",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/yexingshi" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",5); 
        set("coor/y",-1800); 
        set("coor/z",20); 
        setup(); 
//        replace_program(ROOM); 
}  
int valid_leave(object me,string dir) { 
        object ye;
        ye=present("ye xingshi",this_object());
        if (dir=="up" && ye)
        if (!userp(ye)) {
                message_vision(ye->name()+"���˹��֣�ƤЦ�ⲻЦ�ص���$N��ǰ��¥�ݿڡ�\n",me);
                return notify_fail("");
        }
        return 1;
        
}
