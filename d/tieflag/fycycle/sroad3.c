 inherit ROOM;
void create() 
{ 
        set("short", "����С·"); 
        set("long", @LONG 
���߾��Ǹߴ�ķ��Ƴǣ��ϱ�����һ�����ĵ�ƽԭ,ƽԭ�����д�Ƭ��ׯ�ڡ� 
ƽԭ�ľ�ͷ������һ���������淴�������յ���ԡ� 
LONG 
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
  "east" : __DIR__"fysouth", 
  "northwest": __DIR__"sroad2", 
])); 
        set("outdoors", "fengyun"); 
       set("coor/x",-60); 
        set("coor/y",-160); 
        set("coor/z",0); 
            replace_program(ROOM); 
 
        set("coor/x",-60); 
        set("coor/y",-160); 
        set("coor/z",0); 
        setup(); 
} 
       
