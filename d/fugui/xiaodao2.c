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
                "north":__DIR__"yidao1",
                "east":__DIR__"xiaodao1",
                "west":__DIR__"xiaodao3",
        ]) ); 
        set("coor/x",-600);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
