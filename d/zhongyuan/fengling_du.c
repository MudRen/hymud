// fenglin_du.c
inherit ROOM;

void create()
{   
    set("short","�����");
    set("long",@LONG
�ƺ��ڴ���������������������һ���ɿڡ��ഫΪ�Ƶ��װ���ͼ���
��ȵķ������������˵�����Ϊ������ɡ��������׿�ļ���֮�ϣ����
��һ������ľ�帡�ţ����߸��о޴��ͭţ������˨ס�������и�С��ׯ�����
һ�ҿ�ջ�����顰���ɡ����֡��ϰ��������ء�
LONG );
    set("exits",([
        "southwest" : __DIR__"tongguan", 
        "northeast" : __DIR__"zhongtiao_shan1"  ]) );
    set("outdoors","zhongyuan");
    setup();
}

