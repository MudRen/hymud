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
	      set_name("[1;35m����֮��װ[2;37;0m", ({ "fengyun cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;35m��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ��ذ˽������Ǯ��[1;35m����֮��װ[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[31m�����ױ�[2;37;0m�ķ�������
������˼����ŷ��ţ�
[40m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;31mħ[2;37;0m:[1;31m��Ԫ[2;37;0m [36mľ[2;37;0m:[1;31m��Ԫ[2;37;0m [33m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[31m����[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m ����:[35m��׼[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m���Ӻ�[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "dzh");
		set("ownername", "���Ӻ�");
		set("value", 25000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",31);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 31);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 511);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 29);
    set("armor_prop/qi", 53);
    set("armor_prop/jing", 46);
    set("armor_prop/jingli", 46);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",13);
    set("wtypeC",0);
    set("wtypeD",7);
    set("wtypeE",9);
    set("wtypeF",6);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",10);
    set("wtypeK",0);
    set("wtypeL",13);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";