 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ�붴�����Ǳ���һ�����󣬶����ϼ��������Ƶ�ţ�;���������յ�����
�õģ���������ʯ�̳ɣ������˾��ȵ��ǣ�����ʯ��Ȼ��������һ������������
������������ֲֳ棬����ִ�ޡ����װ�͹��ƽ����һ�ɳ�ʪ��ù��֮ζ������
һ�����겻�õ������
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao1",  
        ]));
        set("objects", ([ 
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        this_player()->set("startroom", base_name(this_object()));
}
