 inherit ROOM;
void create()
{
        set("short", "�Ͼ����");
        set("long", @LONG
�������ϱ�����ķϾ�����������������ȣ�ʱ�����������ȥ�����ǿ���
�ܲݣ�˷����ɱ������Ұ�������������ɳҲ��ʱ�������˵�˫�ۣ�Ҳ������ǰ��
������Ρ�
LONG);
        set("type","road");
        set("outdoors", "fugui");
        set("exits",([
                "north":__DIR__"yidao2",
                "south":__DIR__"xiaodao2",
        ]) ); 
        set("coor/x",-600);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
