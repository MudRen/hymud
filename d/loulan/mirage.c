 inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
ͻȻԶԶ��ȥ����ߵ���ϼ�У������ֳ�������Ӱ�ӣ�����������������̣�
�ֵ����ݷ�����ǽ����ϡ�ɱ棬����֮�䣬�Ʋʱ�ã���Щ�����ֹ�����С�һ��
�·����λ�֮�С�
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"sandlin",
                "northwest" : __DIR__"yangguan",
                "west" : "/d/quicksand/desert5",
                "east" : "/d/quicksand/desert6",
        ]));
        set("outdoors", "loulan");
        set("coor/x",-900);
        set("coor/y",100);
        set("coor/z",0);
        setup();
}   
