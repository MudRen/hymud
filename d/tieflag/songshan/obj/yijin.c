 inherit ITEM;
void create()
{
        set_name("�׽", ({ "print" }));
        set_weight(600);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "Ƭ");
            set("long",
         "ʯ�ھ�Ȼ������һ����Ħ�����̬�����������ƣ���Լ�ɼ�������һ����
ɫ��ˮī���������ϣ��������鲼���������������ķ��ţ� 
\n");
                set("no_shown", 1);
                set("no_get", 1);       
                set("material", "stone");
                set("skill", ([
                        "name": "yijinjing",
                        "exp_required": 0,
                        "jing_cost": 20,
                        "difficulty": 40,
                        "max_skill": 200
                ]) );
        }
}  
