 inherit ROOM;
void create()
{
        set("short", "�ϱ����");
        set("long", @LONG
���Ƿ��Ƴǵ�һ����Ҫ��������ϴ���ɽ��ˮ��ֱ���ɻ������½ӷ��ƾ�����
��ͨ���Ϻ��ڡ��������������ò�����һ���������Ϸ��ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : "/d/tieflag/fycycle/fysouth",
  "south" : __DIR__"sroad1",
]));
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",-420);
        set("coor/z",10);
        setup();
}
