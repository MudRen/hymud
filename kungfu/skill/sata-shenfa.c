//sata-shenfa.c.����
//date:1997.9.11
//by dan

inherit SKILL;
string *dodge_msg = ({
"$nһʽ�������հ������������ϱ�ֱ�������࣬������$N������\n",
"$nһʽ���������ǡ���������磬����ݳ�����Զ��$N�����˿���\n",
"$nһʽ��ǧ�ﲻ���С����㲻�����ֲ�̧��ٿ����һ��Ų��������\n",
"$nһʽ�����˷���ȥ�����εض����ڰ����һת�����䵽����Զ\n",
"$n����һת��ʹ��һ�С��������������һת�ۼ���Ƶ���$N�����\n",
});
mapping *action = ({
        ([     
                "action":               
"$nһʽ�������հ������������ϱ�ֱ�������࣬������$N������",
                "lian" :
"$Nһʽ�������հ������������ϱ�ֱ��������",
                "jibie":10,
                "sen"  :5,
        ]),
        ([      "action":
"$nһʽ���������ǡ���������磬����ݳ�����Զ��$N�����˿���",
                "lian" :
"$Nһʽ���������ǡ���������磬����ݳ�����Զ��ȴ����һ�£���Щˤ����",
                "jibie":30,
                "sen"  :5,
        ]),
        ([      
                "action":               
"$nһʽ��ǧ�ﲻ���С����㲻�����ֲ�̧��ٿ����һ��Ų��������",
                "lian" :
"$Nһʽ��ǧ�ﲻ���С����㲻�����ֲ�̧��ٿ����һ��Ų��������",
                "jibie":50,
                "sen"  :5,
        ]),
        ([    
                "action":               
"$nһʽ�����˷���ȥ�����εض����ڰ����һת�����䵽����Զ",
                "lian" :
"$Nһʽ�����˷���ȥ�����εض����ڰ����һת�����䵽����Զ",
                "jibie":70,
                "sen"  :5,
        ]),
        ([      
                "action":               
"$n����һת��ʹ��һ�С��������������һת�ۼ���Ƶ���$N�����",
                "lian" :
"$N����һת��ʹ��һ�С��������������һת�ۼ��ԭ������һȦ",
                "jibie":100,
                "sen"  : 6,
        ]),
});

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("�������̫���ˣ�������������\n");

        return 1;
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}
string perform_action_file(string action)
{
        return __DIR__"sata-shenfa/" + action;
}