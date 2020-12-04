// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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

void create()
{
	set_name("[1;33mÃ¢ÔÂ[2;37;0m", ({ "qiankun sword", "sword" }));
	set_weight(4278);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;33m´ËÎï×óÓÒÁ½±ß·Ö±ğÒÔºÚ°×Á½ÖÖÆæÌúÈÜÖı¶ø³É£¬Ò»ºÚÒ»°×£¬ÇĞºÏÇ¬À¤£¬°üº¬ÒõÑôÖ®Æø£¬ºÃÒ»±ú±¦Îï£¡
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØ°Ë½ïÎåÁ½ÎåÇ®µÄ[1;33mÇ¬À¤Ö®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;36mÍêÃÀ[2;37;0m [31m»ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[1;33mÌìÊ¥[2;37;0m 
[1;37mÀ×[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ÇÉÖÆ:[31m¾«ÖÂ[2;37;0m 
ÖÜÌì:[34mÏ¸Ëé[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÁ½¹û[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "here");
		set("ownername", "Á½¹û");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",32);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",56);
    set("weapon_prop/dodge", 56);
    set("weapon_prop/parry", 40);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 66);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 59);
    set("weapon_prop/jing", 71);
    set("weapon_prop/jingli", 71);
    set("weapon_prop/damage", 35);

    set("wtypeA",8);
    set("wtypeB",0);
    set("wtypeC",7);
    set("wtypeD",9);
    set("wtypeE",6);
    set("wtypeF",10);
    set("wtypeG",9);
    set("wtypeH",6);
    set("wtypeI",6);
    set("wtypeJ",6);
    set("wtypeK",7);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1064);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";