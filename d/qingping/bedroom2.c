 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�˴���κ��̰���˵�ס��,��Ϊκ��̰���԰���,�������о���װ��,Ǯȫ��
κ��̰��ȥ��������,����ǽ��һ������,����һ������,����ʯ��Ϊ�İ���,ʯ
��Ϊ��������,�������Ƿ���,��֪����Ϊ����.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"road2",
])); 
        set("coor/x",150);
        set("coor/y",1990);
        set("coor/z",0);
        setup();
        
        replace_program(ROOM);
}   
