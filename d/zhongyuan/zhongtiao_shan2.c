// zhongtiao_shan2.c
inherit ROOM;

void create()
{   
    set("short","����ɽ");
    set("long",@LONG
����ɽ����һ�������ب�ڻƺӱ����������ǰ���֮һ�Ź�����������֮
��������ë¿���Ź��ϵ�����һֱ�ڱ����Ĵ�ͷ��Ұ�������š���˵�Ƴ�ʱ��
��������죬������¡������گ������������ÿ�������ڴ��͹�ǰ���ض�������
ʬ�����������������ɹ��󲻾ã������˼�������ɽ�����Σ����ɵ�����������
���
LONG );
    set("exits",([
        "west" : __DIR__"zhongtiao_shan1",
        "northeast" : __DIR__"zhongtiao_shan3"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
