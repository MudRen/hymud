// story:caishen ����

#include <ansi.h>

int give_gift(string money, int amount, string name);

private mixed *story = ({
        "��С������·��ꡣ",
        "�������·��",
        "С����ƾʲô��",
        "����񣺷ϻ���ƾ�ұ�����Ǯ��",
        "С������������ͭ�壬�������˳�ȥ���ߺߵ�������",
        (: give_gift, "gold", 60 + random(30), "�ƽ�" :),
        "�����һ����Ц������һЩ�������˳�ȥ��",
        (: give_gift, "gold", 80 + random(30), "�ƽ�" :),
        "С�������˰��죬�ͳ�һЩ�ƽ�ҧҧ�����˳�ȥ����������ѽ��",
        (: give_gift, "gold", 180 + random(30), "�ƽ�" :),
        "�����ǺǴ�Ц������������Ʊ����ƮƮ�ķ��˳�ȥ��",
        (: give_gift, "gold", 180 + random(60), "�ƽ�" :),
        "С����������ɫ������������Ǯ��������Ǯ������·������·��",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift(string money, int amount, string name)
{
        STORY_D->give_gift("/clone/money/" + money, amount,
                           HIM "\n��ž����һ��һЩ" + name + "��������ǰ��\n\n" NOR);
        return 1;
}
