 inherit ROOM;
void create()
{
        set("short", "Ѧ���Ϻ�");
        set("long", @LONG
��������Ѿ������Ｘʮ���ˣ��Կ��ź��û�������棬���û�����ô��ª��
����������еļ��ŷ����ͳ��ʶ��Ѿ�������ԭ������ɫ����������Ƶ��������
��ɢ���������ϣ�ǽ����������ż�֧��ϡϡ�Ŀ��ӣ������ѽ���֩��������ֻ��
ӬäĿ�ط�����ȥ��Ϊ�����������ĵ������˼���������
LONG
        );
        set("exits", ([
                "east" : __DIR__"nwind5",
        ]));
        set("objects", ([
                __DIR__"npc/lifeseller": 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",50);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}
