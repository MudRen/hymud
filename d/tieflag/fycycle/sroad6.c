 inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
���߾��Ǹߴ�ķ��Ƴǣ�����һ����������·��һֱͨ��󺣡�
��·���������������ַǷ�������Щ������Ů��������࣬��ȥΪ��
�º��ս�����˼���ȥ�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 //"east" : "/u/hangzhou/road0",
  "east" :      __DIR__"fyeast",
  "southwest": __DIR__"sroad5",
]));
        set("outdoors", "fengyun");
       set("coor/x",100);
        set("coor/y",-10);
        set("coor/z",0);
 
        set("coor/x",100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();      
}       
