#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;36m���֮��װ[2;37;0m", ({ "tiandi cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;36m���֮����Ů洲��������µ���ؼ�����֮��֮һ��ǧ���������ƣ����ܿ������أ�
[2;37;0m����һ���ɾ��Լ�Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ����Ľ������Ǯ��[1;36m���֮��װ[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m ���������Լ�̣�����[31m�����ױ�[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;35m����[2;37;0m [36mľ[2;37;0m:[1;35m����[2;37;0m [31m��[2;37;0m:[1;35m����[2;37;0m [33m��[2;37;0m:[1;31m����[2;37;0m [1;37m��[2;37;0m:[1;31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[32m�ֲ�[2;37;0m 
��ʯ:[31m����[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m 
����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "����");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 60);
    set("armor_prop/parry", 49);
    set("armor_prop/attack", 58);


    set("armor_prop/armor", 1062);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 59);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 376);

    set("wtypeA",11);
    set("wtypeB",11);
    set("wtypeC",5);
    set("wtypeD",11);
    set("wtypeE",14);
    set("wtypeF",5);
    set("wtypeG",14);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",10);
    set("wtypeK",10);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";