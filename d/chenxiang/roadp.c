 inherit ROOM;
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١����������
���綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ����
һ���������۵Ĺٵ��������Ͷ�����չ��
LONG
        );
        set("exits", ([ 
  ///"northwest" : AREA_QUICKSAND"desert2",
  "south" : __DIR__"road",
]));
        set("outdoors", "chenxiang"); 
        set("coor/x",-520);
        set("coor/y",-420);
        set("coor/z",-10);
        setup();
}
