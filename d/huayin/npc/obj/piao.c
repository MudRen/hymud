// piao.c

inherit ITEM;

protected int full;

int is_shui_piao() { return 1; }
string q_long() { return sprintf("����һ������ʢˮ��ˮư%s",full?"��\n����ʢ������ˮ��\n":"��\n"); }

void create()
{
	set_name("ˮư", ({ "shui piao" }) );
	set_weight(500);

	set("unit", "��");
	set("long", (: q_long :));
}

int is_full() { return full; }
void do_fill() { full = 1; }
void do_pour() { full = 0; }
