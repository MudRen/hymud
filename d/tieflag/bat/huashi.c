 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ӳ��󣬲�֪�δ�����̴֧�㣬����һ���ѳ����׵���ζ��
�������ǽ����һ�����ӣ������ķ��ı���ȫ����������������
�ط�����ֵ��Ƕ�����ܾ�û�����ù���
LONG
        );
        set("exits", ([
                "east" : __DIR__"feng",
            "west" : __DIR__"shushi",
        ])); 
        set("objects", ([
        __DIR__"npc/tong4": 1,
    ])); 
        set("coor/x",3300);
        set("coor/y",30);
        set("coor/z",-20);
        setup();
}     
