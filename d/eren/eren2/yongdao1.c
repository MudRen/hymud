 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long",  @LONG
���߼���������������ڣ����¿���ÿ��ʮ��߱���һת��֮������֪����
�������紵��һ�Ե���������������ϡ�ճ�����������Ѫ��Ĵ��֡�
                ��       ��      ��
        
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao2",
                "southup" : __DIR__"cavein",
        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
