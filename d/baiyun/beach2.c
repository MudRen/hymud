 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "ɳ̲"); 
        set("long", @LONG 
��������ѷֲ��������˼䡣������ã�ɳ̲�����ϸ����ˮտ����̣����� 
�������������İ�ĭ�����ź�������Ŀ�������������죬�����к������ӱ̿գ����� 
�����׺��������ᷫ����������������������������˽��������� 
LONG 
           ); 
        set("exits",  
           ([  
             "west"  : __DIR__"beach", 
             "east"  : __DIR__"seaside", 
            ])); 
         
        set("objects",  
           ([  
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",30); 
        set("coor/y",-680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}
