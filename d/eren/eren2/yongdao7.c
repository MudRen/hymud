 inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ת������һ��ʯ�ţ�����ڵ��º��ϣ���ˮ���̣��ܺڣ��������˰����ɫ��
�����ź��·һ��Ϊ�����м�һ���������û��һ˿�ƻ��ƺ��ѱ���������
��ͨ�򼸼��ƾɵ�Сʯ�ߣ���ߵ�·�澹Ȼ���ò�ʯ�̳ɣ��ƹ���ӳ������Ĺ�â��
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"yard1",
                "north" : __DIR__"jailroad1",
                "northwest" : __DIR__"court1",
                "southup" : __DIR__"yongdao5",
        ]));
        set("item_desc", ([
                "��ˮ": "����һ�����µİ��ӣ�������Լ�����ɣ�����ȥ������ģ�������Щ�̹�������\n",
                "river": "����һ�����µİ��ӣ�������Լ�����ɣ�����ȥ������ģ�������Щ�̹�������\n",
                
        ]) );
        set("objects", ([
                __DIR__"npc/guardb" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
