 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
һ���ƻ�ͨ���ĳ��ȣ��ƺ�ԭ�ȱ��Ƿ����Ľֵ���������һЩ��Ժ��լ����
�������ռ�����¥���ĵ��������󣬱㽫���СС����լ���ݸĽ����Թ�����
��ɫ������ʹ��������ʮ�����Լ��ڶ��������˺�һ�����˾�ס��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"weststrt2",
                "west" : __DIR__"westtower",
        ]));
        set("indoors", "loulan"); 
        set("coor/x",-1030);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
}
