 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��һ�źܴ�ܴ��ʯ�Σ�����һ����ʯͷ���ܳɵģ���Ȼ��ʯͷ����
�����ʸ���Ө����һ˿��ɫ�����������ⶴ������֮����˼�������
ֻҪ������ʯ���ϣ����̾�����ů�紺��
��������ʯ�Σ�����֮�£�ֻ����Ҳ�Ҳ����ڶ�ֻ�ˣ���������ʯ��
ȴ�ѱ�һ���������룡
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"mouseroom2",
                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}       
