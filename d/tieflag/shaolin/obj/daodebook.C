inherit ITEM;
void create()
{
        set_name( "���¾�", ({ "daode book","book" }));
        set_weight(600);
        set("unit", "��");
        set("long", "���ӵ��¾������ӵ��������������˹۵��¾�����һ�£����� �ɵ���\n�ǳ����������������ǳ��������������ʼ������������ĸ�����ޣ�\n����������У��������衣������ͬ��������... 
\n");
        set("value", 200);
        set("skill", ([
                "name":                 "force",             // name of the skill
                //"exp_required": 20000,                              // minimum combat experience required
                                                                                // to learn this skill.
                "jing_cost":             49,                             // gin cost every time study this
                "difficulty":   49,                             // the base int to learn this skill
                                                                                // modify is gin_cost's (difficulty - int)*5%
                "max_skill":    49                              // the maximum level you can learn
                                                                                // from this object.
        ]) );
}