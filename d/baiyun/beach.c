 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "����");
        set("long", @LONG 
��������ѷֲ��������˼䡣������ã�ɳ̲�����ϸ����ˮտ����̣����� 
�������������İ�ĭ�����ź�������Ŀ�������������죬�����к������ӱ̿գ����� 
�����׺��������ᷫ����������������������������˽��������� 
LONG 
           ); 
        set("exits",  
           ([  
             "north" : __DIR__"southsearoad1", 
             "west"  : __DIR__"beach1", 
             "east"  : __DIR__"beach2", 
            ])); 
        set("objects", 
          ([ 
        __DIR__"npc/yueyang" : 1,
        __DIR__"npc/husheng" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
} 
 
