 // Silencer@FY workgroup  ���˿�
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ�붴������һ�����󣬶����ϼ������۴ֵ�ţ�;���������յ������ã���
������ʯ�̳ɣ�������һ������������������������ֲֳ棬����ִ�ޡ�������
һ�ɳ�ʪ��ù��֮ζ������һ�����겻�õ������û�л�ͷ��·����֪��ǰ���ȴ�
�������ʲô��
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
        set("valid_startroom",1);
        setup();
} 
void init()
{
        this_player()->set("startroom", base_name(this_object()));
}     
