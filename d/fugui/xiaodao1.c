 inherit ROOM;
void create()
{
        set("short", "�Ͼ����");
        set("long", @LONG
��������������ķϾ�����������������ȣ�ʱ�����������ȥ�����ǿ���
�ܲݣ�˷����ɱ������Ұ�������������ɳҲ��ʱ�������˵�˫�ۣ�Ҳ������ǰ��
������Ρ�
LONG);
        set("type","road");
        set("outdoors", "fugui");
        set("exits",([
               "east" : "/d/songshan/tianzhongge",
                "west":__DIR__"xiaodao2"
        ]) ); 
        set("coor/x",-400);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
