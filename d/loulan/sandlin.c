 inherit ROOM;
void create()
{
        set("short", "ɳ��");
        set("long", @LONG
������ȥ��ֻ�л�ɳ���ޱ��޼ʣ������޾��Ļ�ɳ��û��ˮ��û��������Ҳ
û��ϣ�����˴���Զ��ϡ������ʱ����û��ɳ�����в�Ᵽ���Ϊ�ɲ�����Ƶ����
��ɳ����������ɳ�ڷ籩�о��裬ɳ���Ϻ�Ȼʬ���ݺᣬѪ��δ�ɡ���ؼ䣬��
����������ɱ֮����
LONG
        );
        set("exits", ([ 
                "south" : "/d/quicksand/greenland",
                "west" : "/d/quicksand/desert6",
                "northeast" : __DIR__"mirage",
                "east" : "/d/quicksand/desert8",
        ]));
        set("outdoors", "loulan"); 
        set("coor/x",-1085);
        set("coor/y",50);
        set("coor/z",0);
        setup();
}
