 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���ڵ�"); 
        set("long", @LONG 
���в�Զ��һ����ΰ׳���Ĵ���������ǰ�������������ڌ�����ͥԺ�º͸ߴ� 
�Ľ�����ǰ����ν��ߵع㣬����Ȼ����С����Ȼ����һ�֡�Ψ�Ҷ��𡱵��������� 
���� 
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"fightdoor",
       "south" : __DIR__"jietiandian",
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-1930); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
}     
