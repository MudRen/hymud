 inherit ROOM;
void create() 
{ 
        set("short", "����С·"); 
        set("long", @LONG 
С�����ŷ��ƳǵĻ��Ǻ�����ȥ���ϱ���һƬ��ľ��������֡� 
�����ﴫ��һ����ı��н�������������ʱ�������ż���ߺ�ȣ�ߺ�ȵ� 
���������㣬һ����֪�������ָ��֡�·�ϵ�����������ǣ�������Щ 
���š� 
LONG 
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
 //"east" : "/u/hangzhou/road0", 
  "northeast" : __DIR__"sroad6", 
  "southwest": __DIR__"sroad4", 
])); 
        set("outdoors", "fengyun"); 
        set("coor/x",40); 
        set("coor/y",-80); 
        set("coor/z",0); 
            replace_program(ROOM); 
 
        set("coor/x",40); 
        set("coor/y",-80); 
        set("coor/z",0); 
        setup(); 
} 
     
