 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "ƽԭ·"); 
        set("long", @LONG 
����Ա����ϣ����ƽ�ƽ��·������Сʯ�ӣ�һ�����������Ϸ��ͱ�����չ���� 
���������棬������Ϊ�ѽš������Ե���ľԽ��Խ�٣������ƻ����������Ҹ��ط� 
��Ϣһ�¡� 
LONG 
           ); 
        set("exits",  
           ([  
             "north" : __DIR__"woodsroad", 
             "south" : __DIR__"southsearoad", 
             "west" : "/d/chenxiang/fydao3",
            ])); 
        set("outdoors", "baiyun"); 
        set("NONPC",1); 
        set("coor/x",10); 
        set("coor/y",-630); 
        set("coor/z",0); 
        setup(); 
} 
 
int valid_leave(object who,string dir) 
{ 
        if(userp(who) && random(3)) 
          { 
           who->move(this_object()); 
           return notify_fail("");  
          } 
        return 1; 
}   
