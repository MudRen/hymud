//Cracked by Roath
// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
"��ѧէ��","�����ž�","��ͨƤë",
"��֪һ��","��������","������",
"����С��","����С��","����Ѿ�",
"�������","��Ȼ����","�������",
"���д��","���д��","�������",
"�޿�ƥ��","����似","�����뻯",
"��Ȼ��ͨ","�Ƿ��켫","����Ⱥ��",
"������˫","һ����ʦ","������",
"����Ⱥ��","��������","��������",
"��������","��ɲ�","���ӹ���", 
"�����޵�"
});

string *knowledge_level_desc = ({
"��ѧէ��","��������","��֪����",
"ƽ������","˾�ռ���","�����ž�",
"��֪һ��","é���ٿ�","��ʶ֮��",
"��������","������","�ᳵ��·",
"��������","������ͨ","����ǳ��",
"����С��","�������","��Ȼ���",
"����ʶ��","������ͨ","׿����Ⱥ",
"��������","��Ȼ��ͨ","����ͨ��",
"������","��Ⱥ����","������˫",
"��������","������","������ʥ",
"��ɲ�"
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i,j;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && !ob->is_spouse_of(me) && !ob->is_baby_of(me))
                return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
			//Add !me->visible(me) by play 2002.7.28  
			// temp removed !me->visible(me) because bug by Xuanyuan

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write("$mybase#"+(ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }
        //if(j>0) { printf("$mybase#��%16s  ������������������������������������������������\n", ""+chinese_number(j)+"��֪ʶ");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge"){
                printf("$mybase#%s%s%-30s" " - %3d/%6d %-5s \n", 
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skl[sname[i]], (int)lrn[sname[i]],
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]])
                );
                }
        }
        j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" ||sname[i] == "unarmed" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        //if(j>0) { printf("$mybase#��%16s  ������������������������������������������������\n", ""+chinese_number(j)+"���������");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" ||sname[i] == "unarmed" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "beidou-zhenfa" )){
                printf("$mybase#%s%s%-30s" " - %3d/%6d %-5s \n", 
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skl[sname[i]], (int)lrn[sname[i]],
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]])
                        
                );
                }
        }
        //if(j>0) { write("$mybase#��������������������������������������������������������������������\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe"&& sname[i] != "unarmed" && sname[i] != "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        //if(j>0) { printf("$myski#��%16s  ������������������������������������������������\n", ""+chinese_number(j)+"�����⹦��");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe"&& sname[i] != "unarmed" && sname[i] != "beidou-zhenfa" )){
                printf("$myski#%s%s%-30s" " - %3d/%6d %-5s \n", 
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skl[sname[i]], (int)lrn[sname[i]],
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]])
                        
                );
                }
        }
        write("$#\n");
        //if(j>0) { write("$myski#��������������������������������������������������������������������\n");}
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 20;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : skills|cha [<ĳ��>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
