 inherit ROOM;
void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
һ��ΡΡ��ɽ�ţ�������д�š�����ɽ�������Ծ��Ĵ��֡��䵱
ɽ����̫��ɽ���������㣬������Σ���Թžͱ���Ϊ�����µ�һ��ɽ����
�ƴ��𣬼��������⽨�ʵ۶�������ֲ�䵱���̣�������������ɽ��
�������������ĳ�ߵ�λ��Ϊȫ�����̵Ļ���ġ�ԶԶ��ȥ������
Ⱥ��ͦ����׿���ƺ���
LONG
        );
        set("exits", ([
                "north" : __DIR__"road1",
                "southup" : __DIR__"road2",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-80);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
