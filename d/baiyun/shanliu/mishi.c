 // Room: mishi.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "����"); 
        set("long", @LONG
���Ǽ��С�����ӣ����Ӻܰ�����ȴ��ʰ������ɾ�������Ҳ����һ�����
վ�Ÿ��ˣ�ż�����ŷ�����üͷ΢�壬�ƺ�������ʲô�鷳�����顣������Ǹ߸�
��ɽ�£��Ա��и�����׵ĺ�̶����Ŀ�Ĺˣ�ֻ��������ݣ��·�һ������Ļ�
԰��������Щʹ����ֵ��ǣ��±���ԭ����ݲ�������ȴ��ͻأ������һ�����̵�
��̦��,�������ϣ�ʯ���Ͽ���һ���֣����������뿪���ֵܸ�����������
LONG);
        //{{ --- by MapMaker
        set("type","house");
        //}}
        set("objects", ([
        __DIR__"npc/yang" :1,
        __DIR__"obj/lichen" :1,
        ]) );
        set("indoors", "shanliu");
        set("coor/x",-100);
        set("coor/y",-580);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}     
