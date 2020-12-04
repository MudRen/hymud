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
	set_name("[1;33mĞÓ»¨·É[2;37;0m", ({ "kunlun sword", "sword" }));
	set_weight(11114);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
[1;36m	Ğ¦½­ºşÀË¼£Ê®ÄêÓÎ£¬¿Õ¸ºÉÙÄêÍ·¡£
	¶ÔÍ­ÍÓÏï²´£¬Ò÷ÇéÃìÃì£¬ĞÄÊÂÓÆÓÆ£¡ 
	¾ÆÁîÊ«²ĞÃÎ¶Ï£¬ÄÏ¹úÕıÇå³î¡£ 
	°Ñ½£ÆàÈ»Íû£¬ÎŞ´¦ÕĞ¹éÖÛ¡£ 
 
	Ã÷ÔÂÌìÑÄÂ·Ô¶£¬ÎÊË­Áô³şÅå£¬ÅªÓ°ÖĞÖŞ£¿
	ÊıÓ¢ĞÛ¶ùÅ®£¬¸©Ñö¹Å½ñ³î¡£
	ÄÑÏûÊÜµÆ»èÂŞÕÊ£¬Øöê¼»¨Ò»ÏÖºŞÄÑĞİ£¡
	Æ®Áã¹ß£¬½ğ¸êÌúÂí£¬Æ´Ôá»ÄÇğ£¡ 
[2;37;0mÕâÊÇÒ»°ÑÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®¶ş½ï¶şÁ½¶şÇ®µÄ[1;36mÀ¥ÂØÖ®½£[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31mÌìÏÂÎŞË«[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;31mÎŞË«[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31m¿ªÔª[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;31m»ÙÌì[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÌåÁé:[1;36mÍêÃÀ[2;37;0m °×Ê¯:[32m´Ö²Ú[2;37;0m ×ÏÊ¯:[32m´Ö²Ú[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m ÍşÁ¦:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÏãÀïĞ¡[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÇá¹¦[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "qing");
		set("ownername", "ÏãÀïĞ¡");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",28);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 34);
    set("weapon_prop/parry", 37);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 71);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 61);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 73);

    set("wtypeA",6);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",13);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(1045);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";